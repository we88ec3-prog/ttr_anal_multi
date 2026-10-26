
void FUN_00668520(int param_1,char param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_18;
  undefined2 local_13;
  undefined4 local_11;
  undefined4 local_d;
  char local_9;
  
  if ((param_2 != '\0') && (*(char *)(param_1 + 0x130) != '\0')) {
    local_18 = (int *)(param_1 + 0x118);
    iVar3 = 0;
    do {
      if (*(int *)(*local_18 + 0x25c) != 0) {
        uVar1 = **(undefined4 **)(param_1 + 0x114);
        uVar2 = (*(undefined4 **)(param_1 + 0x114))[1];
        FUN_004adcd0();
        local_9 = (char)iVar3 + '\x01';
        local_13 = 0x9c;
        local_11 = uVar1;
        local_d = uVar2;
        if (DAT_00fba798 == 0) {
          (**(code **)(*DAT_00fba854 + 0x10))(0,&local_13,0xb);
        }
      }
      local_18 = local_18 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  return;
}

