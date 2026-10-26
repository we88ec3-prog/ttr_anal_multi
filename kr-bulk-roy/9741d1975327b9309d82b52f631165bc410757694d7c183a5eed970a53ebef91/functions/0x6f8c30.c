
void FUN_006f8c30(int param_1)

{
  int iVar1;
  undefined4 *in_EAX;
  undefined4 uVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 local_18;
  int local_10;
  undefined1 local_9 [5];
  
  iVar1 = *(int *)(param_1 + 0x28);
  if (in_EAX[4] == 0) {
    local_10 = iVar1;
    uVar2 = (*(code *)in_EAX[1])(*in_EAX,&local_10,4,in_EAX[2]);
    in_EAX[4] = uVar2;
  }
  if (0 < iVar1) {
    iVar3 = 0;
    local_10 = iVar1;
    do {
      local_9[0] = *(undefined1 *)(*(int *)(param_1 + 8) + 8 + iVar3);
      puVar4 = (undefined8 *)(*(int *)(param_1 + 8) + iVar3);
      if (in_EAX[4] == 0) {
        uVar2 = (*(code *)in_EAX[1])(*in_EAX,local_9,1,in_EAX[2]);
        in_EAX[4] = uVar2;
      }
      iVar1 = *(int *)(puVar4 + 1);
      if (iVar1 == 1) {
        local_9[0] = *(undefined1 *)puVar4;
        if (in_EAX[4] == 0) {
          uVar2 = (*(code *)in_EAX[1])(*in_EAX,local_9,1,in_EAX[2]);
LAB_006f8cef:
          in_EAX[4] = uVar2;
        }
      }
      else if (iVar1 == 3) {
        local_18 = *puVar4;
        if (in_EAX[4] == 0) {
          uVar2 = (*(code *)in_EAX[1])(*in_EAX,&local_18,8,in_EAX[2]);
          goto LAB_006f8cef;
        }
      }
      else if (iVar1 == 4) {
        FUN_006f8ba0();
      }
      iVar3 = iVar3 + 0x10;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  iVar1 = *(int *)(param_1 + 0x34);
  local_10 = iVar1;
  if (in_EAX[4] == 0) {
    uVar2 = (*(code *)in_EAX[1])(*in_EAX,&local_10,4,in_EAX[2]);
    in_EAX[4] = uVar2;
  }
  if (0 < iVar1) {
    iVar3 = 0;
    do {
      FUN_006f8ed0(*(undefined4 *)(*(int *)(param_1 + 0x10) + iVar3 * 4),
                   *(undefined4 *)(param_1 + 0x20));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}

