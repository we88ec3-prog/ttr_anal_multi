
undefined4 FUN_0083b7a0(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int in_ECX;
  int local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_c = 0;
  iVar3 = D3DXCreateEffect(*(undefined4 *)(in_ECX + 0xec),param_2,param_3,0,0,0x805,
                           *(undefined4 *)(in_ECX + 0x3f0),&local_8,&local_c);
  if (iVar3 == 0) {
    param_3 = 0;
    (**(code **)(*local_8 + 0xf4))(local_8,0,&param_3);
    if (param_3 != 0) {
      puVar4 = (undefined4 *)FUN_00863c20(in_ECX + 0x134,param_1,local_8);
      puVar2 = param_4;
      uVar1 = *puVar4;
      *param_4 = uVar1;
      iVar3 = FUN_0083ff20(in_ECX + 0x144,uVar1);
      (**(code **)(*local_8 + 8))(local_8);
      if (*(int *)(iVar3 + 8) == 2) {
        iVar3 = *(int *)(in_ECX + 0x418);
        piVar5 = (int *)FUN_008402e0(*(undefined4 *)(in_ECX + 0x414),iVar3,puVar2);
        if (*piVar5 == iVar3) {
          FUN_0083eab0();
        }
      }
      return 1;
    }
    (**(code **)(*local_8 + 8))(local_8);
  }
  else if ((local_c != 0) && (local_8 != (int *)0x0)) {
    (**(code **)(*local_8 + 8))(local_8);
    return 0;
  }
  return 0;
}

