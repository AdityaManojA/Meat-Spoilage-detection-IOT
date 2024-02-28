// components/DataDisplay.js
import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const DataDisplay = ({ temperature, humidity }) => {
  return (
    <View style={styles.container}>
      <Text style={styles.label}>Temperature: {temperature}°C</Text>
      <Text style={styles.label}>Humidity: {humidity}%</Text>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    marginTop: 20,
    paddingHorizontal: 20,
  },
  label: {
    fontSize: 18,
    marginBottom: 10,
  },
});

export default DataDisplay;
