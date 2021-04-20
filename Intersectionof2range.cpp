think of two range ,
      1. l < -- > r
      2. left < ---> right

      if you want to check if the 2nd range somehow intersect the 1st range ( and vice versa) ??
		      apply this :

		      if (left <= r && right >= l )
		{
			cout << "YES" << endl;
			return;
		}


