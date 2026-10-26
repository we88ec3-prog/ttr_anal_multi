
int FUN_008bb770(undefined4 *param_1,char param_2,undefined4 param_3,int param_4,int param_5,
                int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int local_10;
  int local_8;
  
  iVar1 = *(int *)(in_EAX + 0xc);
  uVar2 = *(undefined4 *)(in_EAX + 8);
  local_10 = 0;
  iVar3 = FUN_008baee0(uVar2,*(undefined4 *)(iVar1 + 0x24),&local_8);
  iVar4 = local_8;
  if (local_8 == 0) {
    *(int *)(iVar3 + 0x60) = in_EAX;
    *(undefined4 *)(iVar3 + 100) = uVar2;
    *(undefined4 *)(iVar3 + 0x68) = *param_1;
    if (param_2 != '\0') {
      *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | 0x400;
    }
    local_10 = FUN_008baee0(uVar2,0x3c,&local_8);
    iVar4 = local_8;
    if (local_8 == 0) {
      *(int *)(iVar3 + 0x80) = local_10;
      *(undefined4 *)(local_10 + 0x30) = 0;
      iVar4 = 0;
      if (0 < param_4) {
        do {
          if (*(int *)(*(int *)(iVar3 + 0x80) + 0x30) != 0) break;
          if (*(int *)(param_5 + iVar4 * 8) == 0x696e6372) {
            *(undefined4 *)(*(int *)(iVar3 + 0x80) + 0x30) =
                 *(undefined4 *)(param_5 + 4 + iVar4 * 8);
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_4);
      }
      if (*(code **)(iVar1 + 0x30) != (code *)0x0) {
        local_8 = (**(code **)(iVar1 + 0x30))(*param_1,iVar3,param_3,param_4,param_5);
      }
      *param_1 = *(undefined4 *)(iVar3 + 0x68);
      iVar4 = local_8;
      if ((local_8 == 0) && ((iVar4 = FUN_008b8520(), iVar4 == 0 || ((char)iVar4 == '&')))) {
        *param_6 = iVar3;
        return local_8;
      }
    }
  }
  local_8 = iVar4;
  FUN_008bb620(uVar2);
  if (*(code **)(iVar1 + 0x34) != (code *)0x0) {
    (**(code **)(iVar1 + 0x34))(iVar3);
  }
  FUN_008b9f80(uVar2,local_10);
  FUN_008b9f80(uVar2,iVar3);
  *param_6 = 0;
  return local_8;
}

