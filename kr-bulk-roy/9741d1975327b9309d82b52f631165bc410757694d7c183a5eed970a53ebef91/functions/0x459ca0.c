
void FUN_00459ca0(void)

{
  undefined4 *in_ECX;
  
  FUN_005d6dd0();
  *in_ECX = FUI::CItemCubeSlot::vftable;
  *(undefined1 *)(in_ECX + 0xa9) = 1;
  in_ECX[0xa6] = 0;
  in_ECX[0xa8] = 0;
  in_ECX[0xaa] = 0;
  in_ECX[0xac] = 0xffffffff;
  in_ECX[0xad] = 0xffffffff;
  in_ECX[0xb0] = 0xffffffff;
  in_ECX[0xb1] = 0xffffffff;
  in_ECX[0xae] = 0;
  in_ECX[0xaf] = 0;
  in_ECX[0xb7] = 7;
  in_ECX[0xb6] = 0;
  *(undefined2 *)(in_ECX + 0xb2) = 0;
  in_ECX[0xb9] = 0xffffffff;
  in_ECX[0xba] = 0xffffffff;
  in_ECX[0xbe] = 0xffffffff;
  in_ECX[0xbf] = 0xffffffff;
  in_ECX[0xbc] = 0;
  in_ECX[0xbd] = 0;
  in_ECX[0xc0] = 0xffffffff;
  return;
}

