
void FUN_00775690(void)

{
  int iVar1;
  int unaff_EDI;
  undefined1 local_c [4];
  undefined4 *local_8;
  
  iVar1 = (**(code **)(**(int **)(unaff_EDI + 0x7c) + 0x4c))
                    (*(int **)(unaff_EDI + 0x7c),0,local_c,0,0);
  if (-1 < iVar1) {
    *local_8 = 0xff000000;
    local_8[1] = 0xff000000;
    local_8[2] = 0xff000000;
    local_8[3] = 0xff000000;
    local_8[4] = 0;
    local_8[5] = 0;
    local_8[6] = 0xff000000;
    local_8[7] = 0;
    local_8[8] = 0;
    (**(code **)(**(int **)(unaff_EDI + 0x7c) + 0x50))(*(int **)(unaff_EDI + 0x7c),0);
  }
  return;
}

