
void FUN_00431500(void)

{
  _Ctypevec *p_Var1;
  int in_ECX;
  _Collvec _Var2;
  _Ctypevec local_18;
  
  p_Var1 = __Getctype(&local_18);
  *(uint *)(in_ECX + 8) = p_Var1->_Page;
  *(short **)(in_ECX + 0xc) = p_Var1->_Table;
  *(int *)(in_ECX + 0x10) = p_Var1->_Delfl;
  *(wchar_t **)(in_ECX + 0x14) = p_Var1->_LocaleName;
  _Var2 = __Getcoll();
  *(_Collvec *)(in_ECX + 0x18) = _Var2;
  return;
}

