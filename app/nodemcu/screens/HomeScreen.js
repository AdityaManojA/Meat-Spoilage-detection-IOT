import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const HomeScreen = ({ value }) => {

  const isSpoilt = value === 1;

  return (
    <View style={styles.container}>
      <View style={styles.header}>
        <Text style={styles.headerText}>ServeGuard</Text>
      </View>
      <View style={styles.content}>
        <Text style={styles.placeholderText}>
          The Provided meat is: {isSpoilt ? 'Spoilt' : 'Not spoilt'}
        </Text>
      </View>
      <View style={styles.header}>
        <Text style={styles.footerText}>Powered by ServeGuard Technologies</Text>
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#F8F8F8',
  },
  header: {
    backgroundColor: '#FFB6C1',
    paddingVertical: 15,
    paddingHorizontal: 20,
    alignItems: 'center',
  },
  headerText: {
    color: '#fff',
    fontSize: 24,
    fontWeight: 'bold',
  },
  content: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
  },
  placeholderText: {
    fontSize: 18,
    textAlign: 'center',
    color: '#333',
  },
  footer: {
    backgroundColor: '#4CAF50',
    paddingVertical: 10,
    paddingHorizontal: 20,
    alignItems: 'center',
    position: 'absolute',
    bottom: 0,
    left: 0,
    right: 0,
  },
  footerText: {
    color: '#fff',
    fontSize: 12,
  },
});

export default HomeScreen;