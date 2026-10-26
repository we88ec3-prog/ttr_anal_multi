
void FUN_0069ea80(int param_1)

{
  double dVar1;
  int iVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  int *in_ECX;
  int *piVar5;
  undefined2 uStack_24;
  int iStack_22;
  int iStack_1e;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00926a0c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (in_ECX == (int *)0x0) {
LAB_0069ead9:
    in_ECX = (int *)0x0;
  }
  else {
    iVar2 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    if (iVar2 != 0x105bd) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      goto LAB_0069ead9;
    }
  }
  if (in_ECX[5] != 0x6a7) {
    ExceptionList = local_14;
    return;
  }
  piVar5 = (int *)in_ECX[6];
  if (piVar5 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar5 + 4))();
    if (iVar2 == 0x105b9) goto LAB_0069eb11;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  piVar5 = (int *)0x0;
LAB_0069eb11:
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    uStack_c = 0;
    FUN_00533f80();
    _atexit((_func_4879 *)&LAB_00bced30);
    uStack_c = 0xffffffff;
  }
  iStack_22 = piVar5[5];
  iStack_1e = iStack_22 >> 0x1f;
  uStack_24 = 0x9b;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_24,10);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    uStack_c = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    uStack_c = 0xffffffff;
  }
  puVar3 = (undefined4 *)FUN_00891268(0x18);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf42b0;
    *puVar3 = FoxUI::FXUIEventB1::vftable;
    *(undefined1 *)(puVar3 + 5) = 0;
  }
  FUN_0058aa50(puVar3);
  DVar4 = timeGetTime();
  dVar1 = (double)(int)(DVar4 + 1000);
  if ((int)(DVar4 + 1000) < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  *(double *)(param_1 + 0x120) = dVar1;
  ExceptionList = local_14;
  return;
}

