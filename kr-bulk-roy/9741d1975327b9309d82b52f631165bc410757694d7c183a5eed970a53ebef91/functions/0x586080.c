
void FUN_00586080(int *param_1)

{
  int iVar1;
  code *pcVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  
  iVar1 = param_1[0x3f];
  while (iVar1 != 0) {
    DVar3 = timeGetTime();
    if ((uint)(param_1[0x3d] + param_1[0x3e]) < DVar3) {
      (**(code **)(*param_1 + 0xd4))();
      puVar4 = (undefined4 *)FUN_00891268(0x14);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = FoxUI::FXUIEvent::vftable;
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0x13a;
      }
      FUN_00748900();
      pcVar2 = *(code **)(*param_1 + 0x184);
      *(undefined1 *)(param_1 + 0x3c) = 1;
      (*pcVar2)();
      DVar3 = timeGetTime();
      param_1[0x3e] = DVar3;
    }
    Sleep(10);
    iVar1 = param_1[0x3f];
  }
  return;
}

