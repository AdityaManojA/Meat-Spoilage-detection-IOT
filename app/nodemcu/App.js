import React, { useState } from 'react';
import { View, Text, Button, Alert } from 'react-native';

const TestConnectionScreen = () => {
  const [connectionStatus, setConnectionStatus] = useState('');

  const testConnection = async () => {
    try {
      const response = await fetch('http://192.168.1.10/');
      if (response.ok) {
        setConnectionStatus('Connection successful');
        Alert.alert('Success', 'Connection made successfully!');
      } else {
        setConnectionStatus('Failed to connect');
        Alert.alert('Failed', 'Failed to connect to the NodeMCU device.');
      }
    } catch (error) {
      setConnectionStatus('Failed to connect');
      Alert.alert('Error', 'An error occurred while attempting to connect.');
    }
  };

  return (
    <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
      <Text>{connectionStatus}</Text>
      <Button title="Test Connection" onPress={testConnection} />
    </View>
  );
};

export default TestConnectionScreen;
