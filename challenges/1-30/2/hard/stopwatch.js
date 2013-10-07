function StopWatch($scope, $timeout)
{
    $scope.laps = [];

    //passed_time is the current timer
    //last tick is what the previous timer's timestamp was
    //timeout is the timeout event
    $scope.elapsed =
    {
        'passed_time': 0,
        'last_tick': null,
        'timeout': null
    };

    $scope.start = function()
    {
        //if no timer is running, then start it
        if($scope.elapsed.timeout == null)
        {
            $scope.tick();

        }
        else
        {
            $scope.pause();
        }
    };

    $scope.pause = function()
    {
        //pause timer if one is currently running
        $timeout.cancel($scope.elapsed.timeout);
        $scope.elapsed.timeout = null;
        $scope.elapsed.last_tick = null;
    };

    //start the clock
    $scope.startTimer = function()
    {
        //i chose 83 milliseconds, because it is prime so there won't be any "patterns" on the stopwatch digits
        $scope.elapsed.timeout = $timeout($scope.tick, 83);
    };

    //each tick will update the timer and then schedule another tick
    $scope.tick = function()
    {
        $scope.updateTick();
        $scope.startTimer();
    }

    //this calculates how much time has passed since the previous tick
    $scope.updateTick = function()
    {
        var tick = new Date().getTime();

        if($scope.elapsed.last_tick != null)
        {
            var diff = tick - $scope.elapsed.last_tick;
            $scope.elapsed.passed_time += diff;
        }

        $scope.elapsed.last_tick = tick;
    }

    //stop the stopwatch
    $scope.stop = function()
    {
        //pause and then clear passed time
        $scope.pause();
        $scope.elapsed.passed_time = 0;
    }

    $scope.timer = function()
    {
        //only doing minutes, seconds and deciseconds

        var time = $scope.elapsed.passed_time;

        var minutes = Math.floor(time / (60 * 1000));
        time = time - (minutes * (60 * 1000));
        var seconds = Math.floor(time / 1000);
        var milliseconds = time - (seconds * 1000);

        //pad everything nicely
        return minutes + ':' + pad(seconds.toString(), 2, '0', STR_PAD_LEFT) + '.' + pad(milliseconds.toString(), 3, '0', STR_PAD_LEFT);
    };

    $scope.lap = function()
    {
        //save the lap
        $scope.laps.push({'time': $scope.timer()});
    }
}

/**
 *
 *  Javascript string pad
 *  http://www.webtoolkit.info/
 *
 **/

var STR_PAD_LEFT = 1;
var STR_PAD_RIGHT = 2;
var STR_PAD_BOTH = 3;

function pad(str, len, pad, dir) {

    if (typeof(len) == "undefined") { var len = 0; }
    if (typeof(pad) == "undefined") { var pad = ' '; }
    if (typeof(dir) == "undefined") { var dir = STR_PAD_RIGHT; }

    if (len + 1 >= str.length) {

        switch (dir){

            case STR_PAD_LEFT:
                str = Array(len + 1 - str.length).join(pad) + str;
                break;

            case STR_PAD_BOTH:
                var right = Math.ceil((padlen = len - str.length) / 2);
                var left = padlen - right;
                str = Array(left+1).join(pad) + str + Array(right+1).join(pad);
                break;

            default:
                str = str + Array(len + 1 - str.length).join(pad);
                break;

        } // switch

    }

    return str;

}