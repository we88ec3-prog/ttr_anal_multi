
void FUN_006d9b30(int param_1,char *param_2,int param_3,undefined2 param_4)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919a9e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((uint)in_ECX[6] < 0x10) {
    piVar4 = in_ECX + 1;
  }
  else {
    piVar4 = (int *)in_ECX[1];
  }
  iVar5 = __stricmp((char *)piVar4,param_2);
  if (iVar5 == 0) {
    ExceptionList = local_10;
    return;
  }
  if (*in_ECX != 0) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_8 = 0xffffffff;
    }
    if (DAT_00fb9335 == '\0') {
      (**(code **)(*(int *)*in_ECX + 0x2c))();
    }
    else {
      FUN_006d9280(0x40400000);
    }
    FUN_00402a70(&DAT_00bf2375,0);
    *in_ECX = 0;
  }
  *(undefined2 *)(in_ECX + 9) = param_4;
  in_ECX[8] = param_3;
  pcVar6 = param_2;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar6 - (int)(param_2 + 1));
  *in_ECX = 0;
  bVar2 = false;
  if (*(int *)(param_1 + 0x2c) != 0) {
    piVar4 = *(int **)(param_1 + 0x28);
    piVar7 = (int *)*piVar4;
    if (piVar7 != piVar4) {
      do {
        if (0.33333334 < (float)piVar7[0xd]) {
          bVar2 = true;
        }
        piVar7 = (int *)*piVar7;
      } while (piVar7 != piVar4);
      if (bVar2) {
        iVar5 = 0x40000000;
        goto LAB_006d9c68;
      }
    }
  }
  iVar5 = 0x3c23d70a;
LAB_006d9c68:
  in_ECX[0xd] = iVar5;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  *(undefined4 *)(param_1 + 0xa8) = 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb4));
  iVar5 = *(int *)(param_1 + 0xac);
  *(undefined4 *)(iVar5 + 0x10) = 1;
  SetEvent(*(HANDLE *)(iVar5 + 0xc));
  ExceptionList = local_10;
  return;
}

