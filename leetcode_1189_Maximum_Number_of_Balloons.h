class Solution {
public:
	int maxNumberOfBalloons(string text) {

		int count = 0;

		std::string balloon = "balloon";

		while (1)
		{
			bool isBreak = false;

			for (int i = 0; i < balloon.size(); i++)
			{
				auto it = std::find(text.begin(), text.end(), balloon[i]);

				if (it == text.end())
				{
					isBreak = true;
					break;
				}

				text.erase(it);
			}

			if (false == isBreak)
			{
				count++;
			}
			else
			{
				break;
			}
		}

		return count;

	}
};
