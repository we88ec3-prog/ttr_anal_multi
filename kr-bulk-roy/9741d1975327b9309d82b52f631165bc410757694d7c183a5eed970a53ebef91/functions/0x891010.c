
void FUN_00891010(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  *in_ECX = std::exception::vftable;
  *(undefined1 *)(in_ECX + 2) = 0;
  return;
}

