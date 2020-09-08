#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main()
{
  int n, input, now = 1, val;
  queue<int> seq;
  stack<int> arr;
  vector<string> answer;

  arr.push(1);
  answer.push_back("+");
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> input;
    seq.push(input);
  }

  while (seq.size() > 0)
  {
    val = seq.front();
    if (arr.size() == 0 || arr.top() < val)
    {
      now++;
      arr.push(now);
      answer.push_back("+");
    }
    else if (arr.top() == val)
    {
      answer.push_back("-");
      arr.pop();
      seq.pop();
    }
    else
    {
      answer.clear();
      answer.push_back("NO");
      break;
    }
  }

  for (auto ans : answer)
    cout << ans << "\n";
  return 0;
}

// 예전에 푼 방법
/*
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
using namespace std;


int n, value;
queue<int> sequence; // 만들 순열
//queue<string> answer;
vector<char> answer;

int main()
{
	stack<int> stack; // 빠지지 않고 저장된 값
	bool flag = true;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> value;
		sequence.push(value);
		//sequence.push(i + 1);
	}
	
	do
	{
		for (int i = 0; i < n; i++)
		{
			stack.push(i + 1);
 			//answer.push("+");
			answer.push_back('+');
			//cout << "+" << endl;

			// 뽑아야 하는 값이 더 큰 경우
			if (stack.top() > sequence.front())
			{
				//cout << "NO" << endl;
				flag = false;
				break;
			}
			else if (i + 1 == sequence.front())
			{
				do
				{
					stack.pop();
					sequence.pop();
					//answer.push("-");
					answer.push_back('-');
					//cout << "-" << endl;
					if (sequence.empty()) break;
					if (stack.empty())
					{
						break;
					}
					if (sequence.front() < stack.top())
					{
						flag = false;
					}
				} while (sequence.front() == stack.top());
			}
		}
		if (!stack.empty() || !sequence.empty() || flag == false)
		{
				cout << "NO" << "\n";
				flag = false;
				break;
		}
	} while (!sequence.empty() && !stack.empty() && flag != false);

	if (flag == true)
	{
		//while (!answer.empty())
		//{
		for (auto it = answer.begin(); it != answer.end(); it++)
			cout << *it << "\n";
			//cout << answer.front() << endl;
			//answer.pop();
		//}
	}

	return 0;
  }
  */

// 예전에 푼 방법 2
/*
 #include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int n, value;
	stack<int> st;
	vector<int> seq;
	vector<char> answer;
	bool flag = true;
	int it = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> value;
		seq.push_back(value);
	}
	
	for (int i = 0; i < n; i++)
	{
		while(1)
		{
			if (st.empty())
			{
				st.push(it);
				answer.push_back('+');
				it++;
			}
			else if (st.top() == seq[i])
			{
				st.pop();
				answer.push_back('-');
				break;
			}
			else if (st.top() > seq[i])
			{
				cout << "NO" << endl;
				return 0;
			}
			else
			{
				st.push(it);
				answer.push_back('+');
				it++;
			}
		}
	}
	if (flag == true)
	{
		for (auto it = answer.begin(); it != answer.end(); it++)
			printf("%c\n", *it);
	}

	return 0;
}
*/