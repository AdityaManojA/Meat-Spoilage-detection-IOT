// App.js
import React, { useEffect, useState } from 'react';
import { View, StyleSheet } from 'react-native';
import HomeScreen from './screens/HomeScreen';

const App = () => {
  const [sensorValue, setSensorValue] = useState(null);

  useEffect(() => {
    fetchSensorValue();
  }, []);

  const fetchSensorValue = async () => {
    try {
     
      const response = await fetch('http://192.168.1.10/value');
      const data = await response.json();
      setSensorValue(data.value);
    } catch (error) {
      console.error('Error fetching sensor value:', error);
    }
  };
  

  return (
    <View style={styles.container}>
      <HomeScreen value={sensorValue} />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#FFB6C1',
  },
});

export default App;
