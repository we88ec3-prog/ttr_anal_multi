
void FUN_00459180(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  *in_ECX = FUI::CItemCubeCoinSlot::vftable;
  in_ECX[0xa6] = 0;
  in_ECX[0xa8] = 0xffffffff;
  in_ECX[0xa9] = 0xffffffff;
  in_ECX[0xac] = 0xffffffff;
  in_ECX[0xad] = 0xffffffff;
  in_ECX[0xaa] = 0;
  in_ECX[0xab] = 0;
  in_ECX[0xb3] = 7;
  in_ECX[0xb2] = 0;
  *(undefined2 *)(in_ECX + 0xae) = 0;
  in_ECX[0xb5] = 0xffffffff;
  in_ECX[0xb6] = 0xffffffff;
  in_ECX[0xba] = 0xffffffff;
  in_ECX[0xbb] = 0xffffffff;
  in_ECX[0xb8] = 0;
  in_ECX[0xb9] = 0;
  in_ECX[0xbc] = 0xffffffff;
  return;
}

