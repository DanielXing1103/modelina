#include <iostream>
#include <cassert>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>

Address address = new Address();

// Unit test for Address serialization
void before() {
		address.setStreetName("Test address 2");
		address.setHouseNumber(2d);
		address.setMarriage(true);
		address.setMembers(2);
		address.setArrayType(new Object[] {Integer.valueOf(2), "test"});
		NestedObject obj = new NestedObject();
		obj.setTest("test");
		address.setNestedObject(obj);
}
void shouldBeAbleToSerializeModel() 
    {
    	ObjectMapper objectMapper = new ObjectMapper();
    	string json = objectMapper.writeValueAsString(address);
        assert( json != null );
		assert(json.length() != 0);
    }

// Unit test for additional properties in serialized output
void shouldNotContainAdditionalPropertiesWhenSerialized() {
    // Arrange
    Address address;
    // Set address properties

    // Act
    std::string json = address.toJson();

    // Assert
    assert(!json.empty());
    assert(json.find("additionalProperties") == std::string::npos);
}

int main() {	
    before()

    try {
        shouldBeAbleToSerializeModel(); 
        shouldNotContainAdditionalPropertiesWhenSerialized();
        std::cout << "All tests passed successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
