
int FUN_008f30a0(int *param_1,undefined1 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int local_8;
  
  iVar1 = *param_1;
  if ((char)param_1[0x49] == '\0') {
    iVar2 = *(int *)(*(int *)(iVar1 + 0x60) + 0x1c);
  }
  else {
    iVar2 = param_1[0x4a];
  }
  if (iVar2 == 0) {
    return 0x99;
  }
  FUN_008ec000(iVar2,iVar1);
  *(undefined4 *)(iVar2 + 0x1ac) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined1 *)(iVar2 + 0x1e8) = 0;
  *(undefined1 *)(iVar2 + 0x231) = param_2;
  FUN_008ebea0(*(undefined4 *)(iVar1 + 0x27c));
  FUN_008ebec0();
  if (*(int *)(iVar1 + 0x27c) == 0) {
    local_8 = 0;
  }
  else {
    local_8 = FUN_008ebe70(0);
    if ((local_8 == 0) && ((char)param_1[0x49] == '\0')) {
      local_8 = (**(code **)(iVar1 + 0x28c))(iVar2);
    }
  }
  *(undefined2 *)(iVar2 + 0x11c) = 0;
  *(undefined2 *)(iVar2 + 0x15c) = 1;
  *(undefined4 *)(iVar2 + 0x130) = 1;
  *(undefined4 *)(iVar2 + 0x122) = 0x4000;
  *(undefined4 *)(iVar2 + 0x126) = 0x4000;
  *(undefined4 *)(iVar2 + 0x12a) = 0x4000;
  *(undefined4 *)(iVar2 + 0x11e) = 0;
  *(undefined4 *)(iVar2 + 0x158) = 0x10001;
  piVar3 = (int *)(iVar2 + 0x11c);
  piVar4 = param_1 + 0x2b;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  FUN_008ec220();
  return local_8;
}

