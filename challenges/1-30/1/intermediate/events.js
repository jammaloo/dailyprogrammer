function EventManager($scope)
{
    $scope.events =
    [
        { 'text': 'Sample Event', 'date': '2013-10-07', 'time': '12:00' },
        { 'text': 'Other Sample Event', 'date': '2013-10-14', 'time': '15:00' },
    ];

    //add a new event
    $scope.addEvent = function()
    {
        $scope.events.push( { 'text': $scope.eventText, 'date': $scope.eventDate, 'time': $scope.eventTime } )
    };

    //delete an existing event
    $scope.deleteEvent = function(index)
    {
        $scope.events.splice(index, 1);
    };

    //get the event date in a readable format
    $scope.getDate = function(index)
    {
        return $scope.events[index].date + ' ' + $scope.events[index].time;
    };

    //get the number of events
    $scope.numEvents = function()
    {
        return $scope.events.length;
    };
}