
void FUN_00555ff0(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  cVar1 = *(char *)((int)param_1 + 0x21);
  while (cVar1 == '\0') {
    FUN_00555ff0(param_1[2]);
    piVar2 = (int *)*param_1;
    puVar4 = (undefined4 *)param_1[4];
    if (puVar4 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)param_1[5];
      for (; puVar4 != puVar3; puVar4 = puVar4 + 7) {
        if (0xf < (uint)puVar4[5]) {
          FUN_0089120c(*puVar4);
        }
        puVar4[5] = 0xf;
        puVar4[4] = 0;
        *(undefined1 *)puVar4 = 0;
      }
      FUN_0089120c(param_1[4]);
    }
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  return;
}

