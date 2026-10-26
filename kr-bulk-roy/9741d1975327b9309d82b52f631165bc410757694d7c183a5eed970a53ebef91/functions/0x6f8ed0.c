
void FUN_006f8ed0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uStack_11;
  int local_10;
  undefined4 uStack_c;
  
  FUN_006f8ba0();
  local_10 = *(int *)(param_1 + 0x3c);
  if (param_3[4] == 0) {
    uVar2 = (*(code *)param_3[1])(*param_3,&local_10,4,param_3[2]);
    param_3[4] = uVar2;
  }
  local_10 = *(int *)(param_1 + 0x40);
  if (param_3[4] == 0) {
    uVar2 = (*(code *)param_3[1])(*param_3,&local_10,4,param_3[2]);
    param_3[4] = uVar2;
  }
  uStack_11 = *(undefined1 *)(param_1 + 0x48);
  if (param_3[4] == 0) {
    uVar2 = (*(code *)param_3[1])(*param_3,&uStack_11,1,param_3[2]);
    param_3[4] = uVar2;
  }
  uStack_11 = *(undefined1 *)(param_1 + 0x49);
  if (param_3[4] == 0) {
    uVar2 = (*(code *)param_3[1])(*param_3,&uStack_11,1,param_3[2]);
    param_3[4] = uVar2;
  }
  uStack_11 = *(undefined1 *)(param_1 + 0x4a);
  if (param_3[4] == 0) {
    uVar2 = (*(code *)param_3[1])(*param_3,&uStack_11,1,param_3[2]);
    param_3[4] = uVar2;
  }
  uStack_11 = *(undefined1 *)(param_1 + 0x4b);
  if (param_3[4] == 0) {
    uVar2 = (*(code *)param_3[1])(*param_3,&uStack_11,1,param_3[2]);
    param_3[4] = uVar2;
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  uStack_c = *(undefined4 *)(param_1 + 0xc);
  local_10 = iVar1;
  if (param_3[4] == 0) {
    iVar3 = (*(code *)param_3[1])(*param_3,&local_10,4,param_3[2]);
    param_3[4] = iVar3;
    if (iVar3 == 0) {
      uVar2 = (*(code *)param_3[1])(*param_3,uStack_c,iVar1 * 4,param_3[2]);
      param_3[4] = uVar2;
    }
  }
  FUN_006f8c30(param_1);
  FUN_006f8d60(param_1);
  return;
}

