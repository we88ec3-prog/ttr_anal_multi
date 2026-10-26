
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006610e0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  piVar3 = (int *)(in_EAX + 0x168);
  iVar2 = 0x10;
  do {
    iVar1 = *piVar3;
    if (*(int *)(iVar1 + 0x29c) == param_1) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_a = *(undefined1 *)(iVar1 + 0x298);
      local_9 = *(undefined1 *)(iVar1 + 0x29c);
      local_c = 0xbd;
      local_8 = 0;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,8);
      }
      (**(code **)(**(int **)(iVar1 + 0x2a4) + 0x90))(1);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

