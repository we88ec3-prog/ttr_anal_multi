
void FUN_006f8d60(int param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  if (in_EAX[3] == 0) {
    iVar3 = *(int *)(param_1 + 0x30);
  }
  else {
    iVar3 = 0;
  }
  local_c = *(int *)(param_1 + 0x14);
  if (in_EAX[4] == 0) {
    local_8 = iVar3;
    iVar1 = (*(code *)in_EAX[1])(*in_EAX,&local_8,4,in_EAX[2]);
    in_EAX[4] = iVar1;
    if (iVar1 == 0) {
      uVar2 = (*(code *)in_EAX[1])(*in_EAX,local_c,iVar3 * 4,in_EAX[2]);
      in_EAX[4] = uVar2;
    }
  }
  if (in_EAX[3] == 0) {
    local_8 = *(int *)(param_1 + 0x38);
  }
  else {
    local_8 = 0;
  }
  iVar3 = local_8;
  local_c = local_8;
  if (in_EAX[4] == 0) {
    uVar2 = (*(code *)in_EAX[1])(*in_EAX,&local_c,4,in_EAX[2]);
    in_EAX[4] = uVar2;
  }
  if (0 < iVar3) {
    iVar3 = 0;
    do {
      FUN_006f8ba0();
      local_c = *(int *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
      if (in_EAX[4] == 0) {
        uVar2 = (*(code *)in_EAX[1])(*in_EAX,&local_c,4,in_EAX[2]);
        in_EAX[4] = uVar2;
      }
      local_10 = *(int *)(iVar3 + 8 + *(int *)(param_1 + 0x18));
      if (in_EAX[4] == 0) {
        uVar2 = (*(code *)in_EAX[1])(*in_EAX,&local_10,4,in_EAX[2]);
        in_EAX[4] = uVar2;
      }
      iVar3 = iVar3 + 0xc;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  if (in_EAX[3] == 0) {
    iVar3 = *(int *)(param_1 + 0x24);
  }
  else {
    iVar3 = 0;
  }
  local_10 = iVar3;
  if (in_EAX[4] == 0) {
    uVar2 = (*(code *)in_EAX[1])(*in_EAX,&local_10,4,in_EAX[2]);
    in_EAX[4] = uVar2;
  }
  iVar1 = 0;
  if (0 < iVar3) {
    do {
      FUN_006f8ba0();
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar3);
  }
  return;
}

