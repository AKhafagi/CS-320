function InfixToPostfix(str)
  tokens = split(str," ")
  stack = {}
  postfix = " "
  top = 1
  val = ""
  
  for key, value in pairs(tokens) 
  do
    if value == "(" 
    then
      stack[top] = value
      top = top+1
    elseif value == ")"
      then
        val = stack[top-1];
        stack[top-1] = nil
        top = top-1
        while(val ~= "(")
        do
          postfix = postfix .. " " .. val
          val = stack[top-1]
          stack[top-1] = nil
          top =top-1
        end
     elseif isOperator(value) == true
      then
        while(isEmpty(stack) == false and comparePrecedence(stack[top-1],value) == true and stack[top-1] ~= "(" )
        do
            postfix = postfix .. " " .. stack[top-1]
            stack[top-1] = nil
            top = top-1;
        end
            stack[top] = value
            top = top +1;
    else
        if postfix == " " 
        then
          postfix = value
        else
        postfix = postfix .. " " .. value
      end
  end
end
  while(isEmpty(stack) == false)
  do
    postfix = postfix .. " " .. stack[top-1]
    stack[top-1] = nil;
    top = top-1
  end
return postfix
end

function split(str,delim)
  tokens = {}
  for match in (str..delim):gmatch("(.-)"..delim) do
    if(match ~= '' and match ~= nil)
    then
        table.insert(tokens, match);
    end
  end
      return tokens
end
function isOperator(str)
  if(str == "+" or str == "-" or str == "*" or str == "/" or str == "^")
  then
    return true
  end
  return false
end
function isEmpty(t)
  for key,value in pairs(t) do
    return false
  end
  return true;
end

function comparePrecedence(a,b)
   if a == '^' 
   then
     return true;
   end
    if b == "^" 
    then
      return false;
    end
    if a == "*"  or  a == "/"
    then
      return true;
    end
    if b == "*" or b == "/"
    then
      return false;
    end
      return true;
end
