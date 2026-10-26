
undefined4 FUN_008b8e10(int *param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_c [4];
  undefined4 local_8;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    piVar1 = *(int **)(*param_1 + 0x60);
    pcVar2 = *(code **)(*piVar1 + 0x20);
    if (pcVar2 != (code *)0x0) {
      puVar3 = (undefined4 *)(*pcVar2)(piVar1,"tt-cmaps");
      if (puVar3 != (undefined4 *)0x0) {
        iVar4 = (*(code *)*puVar3)(param_1,local_c);
        if (iVar4 == 0) {
          return local_8;
        }
      }
    }
  }
  return 0xffffffff;
}

