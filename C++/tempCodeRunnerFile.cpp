while (queues.size() != 0)
        // {
        //     int tuSo = arr[arr.size()-1];
        //     double minValue = INT_MAX;
        //     for (auto i = queues.begin(); i != queues.end(); i++)
        //     {
        //         int v = INT_MAX;
        //         if (i->second.empty())
        //         {
        //             v = i->first;
        //             queues.erase(i);
        //         }
        //         else
        //         {
        //             v = i->second.front() / i->first;
        //             if (v < minValue)
        //             {
        //                 minValue = v;
        //                 tuSo = i->first;
        //             }
        //         }
        //     }
        //     nums.push_back({tuSo,queues[tuSo].front()});
        //     queues[tuSo].pop();
        // }