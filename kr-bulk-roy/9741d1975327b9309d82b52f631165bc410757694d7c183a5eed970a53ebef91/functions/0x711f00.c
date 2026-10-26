
void FUN_00711f00(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  int local_8;
  
  do {
    if (in_EAX == -1) {
      return;
    }
    iVar1 = in_EAX * 4;
    uVar2 = *(uint *)(iVar1 + *(int *)(*param_1 + 0xc)) >> 0xe;
    if (uVar2 == 0x1fffe) {
      local_8 = -1;
    }
    else {
      local_8 = (uVar2 - 0x1fffe) + in_EAX;
    }
    iVar3 = FUN_00711df0(param_1);
    if (iVar3 == 0) {
      iVar3 = param_4 - in_EAX;
      uVar2 = (int)(iVar3 - 1U) >> 0x1f;
      if (0x1ffff < (int)((iVar3 - 1U ^ uVar2) - uVar2)) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(param_1[3],"control structure too long",*(undefined4 *)(param_1[3] + 0x10));
      }
    }
    else {
      iVar3 = param_2 - in_EAX;
      uVar2 = (int)(iVar3 - 1U) >> 0x1f;
      if (0x1ffff < (int)((iVar3 - 1U ^ uVar2) - uVar2)) {
                    /* WARNING: Subroutine does not return */
        FUN_006ff130(param_1[3],"control structure too long",*(undefined4 *)(param_1[3] + 0x10));
      }
    }
    *(uint *)(*(int *)(*param_1 + 0xc) + iVar1) =
         (iVar3 + 0x1fffe) * 0x4000 ^ *(uint *)(*(int *)(*param_1 + 0xc) + iVar1) & 0x3fff;
    in_EAX = local_8;
  } while( true );
}

