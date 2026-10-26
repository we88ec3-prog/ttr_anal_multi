
void FUN_00891123(void)

{
  exception *in_ECX;
  
  *(undefined ***)in_ECX = std::exception::vftable;
  std::exception::_Tidy(in_ECX);
  return;
}

