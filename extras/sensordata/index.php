<!DOCTYPE html>
<html>
<head>
    <meta http-equiv="refresh" content="5">
    <title>Sensor Data</title>
</head>
<body style="background-color: #fafafa; color: #444; font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif; font-size: 16px; text-align: center;">

<h1 style="color: #ff7f00; font-family: 'Arial Black', Gadget, sans-serif; font-size: 28px; text-decoration: underline;">SENSOR DATA</h1>

<table style="margin: 20px auto; width: 90%; border-collapse: collapse; border: 2px solid #ffa94d;">
    <thead>
        <tr> 
            <th style="padding: 15px; border: 1px solid #ffa94d; background-color: #ffc078; color: #fff; font-weight: bold; font-family: 'Arial', 'Helvetica Neue', Helvetica, sans-serif;">ID</th> 
            <th style="padding: 15px; border: 1px solid #ffa94d; background-color: #ffc078; color: #fff; font-weight: bold; font-family: 'Arial', 'Helvetica Neue', Helvetica, sans-serif;">Date & Time</th> 
            <th style="padding: 15px; border: 1px solid #ffa94d; background-color: #ffc078; color: #fff; font-weight: bold; font-family: 'Arial', 'Helvetica Neue', Helvetica, sans-serif;">Sensor</th> 
            <th style="padding: 15px; border: 1px solid #ffa94d; background-color: #ffc078; color: #fff; font-weight: bold; font-family: 'Arial', 'Helvetica Neue', Helvetica, sans-serif;">Ammonia Concentration</th>    
            <th style="padding: 15px; border: 1px solid #ffa94d; background-color: #ffc078; color: #fff; font-weight: bold; font-family: 'Arial', 'Helvetica Neue', Helvetica, sans-serif;">Status</th>     
        </tr>
    </thead>
    <tbody>
    <?php
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "kscste";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    $sql = "SELECT id, sensor, value1, Sstatus, reading_time FROM sensordata ORDER BY id DESC"; /*select items to display from the sensordata table in the database*/

    if ($result = $conn->query($sql)) {
        while ($row = $result->fetch_assoc()) {
            $row_id = $row["id"];
            $row_reading_time = $row["reading_time"];
            $row_sensor = $row["sensor"];
            $row_value1 = $row["value1"];
            $row_Sstatus = $row["Sstatus"];
                 
            echo '<tr> 
                    <td style="padding: 15px; border: 1px solid #ffa94d;">' . $row_id . '</td> 
                    <td style="padding: 15px; border: 1px solid #ffa94d;">' . $row_reading_time . '</td> 
                    <td style="padding: 15px; border: 1px solid #ffa94d;">' . $row_sensor . '</td> 
                    <td style="padding: 15px; border: 1px solid #ffa94d;">' . $row_value1 . '</td> 
                    <td style="padding: 15px; border: 1px solid #ffa94d;">' . $row_Sstatus . '</td> 
                  </tr>';
        }
        $result->free();
    }

    $conn->close();
    ?>
    </tbody>
</table>

</body>
</html>
