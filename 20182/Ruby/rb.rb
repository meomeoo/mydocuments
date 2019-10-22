class Parent
  def say_hi
    p "Hi from Parent."
  end
end

class Child
  def say_hi
    p "Hi from Child."
  end

end

lad = Child.new
puts lad.instance_of? Child
puts lad.instance_of?  Parent