
void FUN_006de410(undefined4 param_1,undefined4 param_2)

{
  _Ctypevec *p_Var1;
  undefined4 *in_ECX;
  _Ctypevec local_14;
  
  in_ECX[1] = param_2;
  *in_ECX = std::ctype<char>::vftable;
  p_Var1 = __Getctype(&local_14);
  in_ECX[2] = p_Var1->_Page;
  in_ECX[3] = p_Var1->_Table;
  in_ECX[4] = p_Var1->_Delfl;
  in_ECX[5] = p_Var1->_LocaleName;
  return;
}

