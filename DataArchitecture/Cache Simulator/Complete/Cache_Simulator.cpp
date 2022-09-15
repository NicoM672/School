#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 1000;
int main(int argc, char *argv[])
{

  /* check if the correct number of arguments have been passed; bail otherwise */
  if (argc < 4) {
    cout << "Usage: " << endl;
    cout << "   ./cache num_entries associativity filename" << endl;
    return 0;
  }

  /* get args; all args come in as strings; need to convert to int with atoi() */
  unsigned entries = atoi(argv[1]);
  unsigned assoc = atoi(argv[2]);
  string input_filename = argv[3];


  if (argc < 2) {
    cout << "Usage: " << endl;
    cout << "   ./file_process filename" << endl;
    return 0;
  }

  /* create input and output files streams */
  ifstream input;


  /* open input stream for reading */
  input.open(input_filename);

  /* check if input stream has been succesfully opened; bail otherwise */
  if (!input.is_open()) {
    cerr << "Could not open input file " << input_filename << ". Exiting ..." << endl;
    exit(0);
  }

  unsigned long *mem = new unsigned long[MAX_SIZE];
  int count = 0;
  while (!input.eof() && count < MAX_SIZE) {
    input >> mem[count];
    count++;
  }

  /* done reading from input file; close the stream */
  input.close();

  int arr[entries][2];
  int counter = 0;
  for(int i = 0; i < entries; i++)
  {
      if(assoc >= 2)
      {
        if(counter == entries/assoc)
        {
          counter = 0;
        }
      }
      arr[i][0] = counter;
      counter++;
  }
  for(int i = 0; i < entries; i++)
  {
      arr[i][1] = NULL;
  }


  /* print the args */
  cout << "Number of entries: " << entries << endl;
  cout << "Associativity: " << assoc << endl;
  cout << "File Name: " << input_filename << endl;
  
  int **last = new int*[2];
  int **current = new int*[2];
  int holder = 0;


  ofstream output("OutputFile.txt");
  for(int i = 0; i < count; i++)
  {
    bool found = false;
    holder = mem[i];
    holder = holder % 2;
    for(int j = 0; j < entries; j++)
    {
      if(arr[j][1] == mem[i])
      {
        found = true;
      }
    }
    if(found == false)
    {
      output << mem[i] << ": Miss" << endl;
      cout << mem[i] << ": Miss" << endl;
      for(int k = 0; k < entries; k++)
      {
        current[0] = &arr[k][0];
        current[1] = &arr[k][0];

        if(assoc !=1)
        {
          if(mem[i] > 1 && arr[k][0] == mem[i] && last[1] != current[1])
          {
            arr[k][1] = mem[i];
            last[1] = current[1];
            break;
          }
          else if(arr[k][0] == holder && last[0] != current[0])
          {
            arr[k][1] = mem[i];
            last[0] = current[0];
            break;
          }
        }
        else
        {
          if(arr[k][0] == mem[i] && last[1] != current[1])
          {
            arr[k][1] = mem[i];
            last[1] = current[1];
            break;
          }
          else if(arr[k][0] == holder && last[0] != current[0] && mem[i] >= (entries/assoc))
          {
            arr[k][1] = mem[i];
            last[0] = current[0];
            break;
          }
        }
      }
    }
    else
    {
      cout << mem[i] << ": Hit" << endl;
      output << mem[i] << ": Hit" << endl;
    }
  }

  output.close();
  return 0;
}
