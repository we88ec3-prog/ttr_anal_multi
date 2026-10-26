
int FUN_008ba850(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
    return 0x21;
  }
  if (param_2 != 0) {
    uVar3 = FUN_008ba070(param_1 + 0x94,param_2);
    if ((int)uVar3 == 0) {
      return 6;
    }
    FUN_008ba0f0((int)((ulonglong)uVar3 >> 0x20),(int)uVar3);
    if (*(int *)(param_2 + 0x10) == 0x6f75746c) {
      *(int *)(param_1 + 0x9c) = param_2;
    }
    if (param_3 != 0) {
      pcVar1 = *(code **)(*(int *)(param_2 + 0xc) + 0x34);
      do {
        iVar2 = (*pcVar1)(param_2,*param_4,param_4[1]);
        if (iVar2 != 0) {
          return iVar2;
        }
        param_4 = param_4 + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    return 0;
  }
  return 6;
}

