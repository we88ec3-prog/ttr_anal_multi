
int FUN_008dbca0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_20;
  int local_1c;
  int local_8;
  
  uVar2 = *(undefined4 *)(param_1 + 100);
  FUN_008dbaf0();
  local_8 = FUN_008daf80(*(undefined4 *)(param_1 + 0x88));
  if (local_8 == 0) {
    local_8 = FUN_008db630(param_1);
    if ((local_8 == 0) && (-1 < param_2)) {
      puVar1 = (undefined4 *)FUN_008baee0(uVar2,0x28,&local_8);
      *(undefined4 **)(param_1 + 0x148) = puVar1;
      if (local_8 == 0) {
        if (local_1c == 0) {
          puVar4 = *(undefined4 **)(param_1 + 0x68);
          for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar1 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar1 = puVar1 + 1;
          }
          *(undefined4 *)(param_1 + 0x134) = local_20;
        }
        else {
          uVar2 = FUN_008baee0(uVar2,local_1c,&local_8);
          *(undefined4 *)(param_1 + 0x144) = uVar2;
          if (local_8 != 0) goto LAB_008dbda8;
          iVar3 = FUN_008dbb10(local_1c,local_20,param_1);
          if (iVar3 != 0) goto LAB_008dbda8;
          FUN_008b9790(*(undefined4 *)(param_1 + 0x148),*(undefined4 *)(param_1 + 0x144),local_1c);
          *(undefined4 *)(param_1 + 0x134) = 0;
        }
        local_8 = FUN_008db790(param_1);
      }
    }
  }
LAB_008dbda8:
  thunk_FUN_008db300();
  return local_8;
}

