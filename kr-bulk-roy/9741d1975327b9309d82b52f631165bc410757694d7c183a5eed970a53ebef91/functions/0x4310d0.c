
void FUN_004310d0(void)

{
  int in_EAX;
  
  FUN_00431040();
  *(undefined ***)(in_EAX + 0x60) = std::ios_base::vftable;
  std::ios_base::_Ios_base_dtor((ios_base *)(in_EAX + 0x60));
  return;
}

