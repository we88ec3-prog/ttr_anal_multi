
void FUN_007f2c70(undefined4 param_1,float param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_2 < 0.0) || (puVar1 = *(undefined4 **)(in_ECX + 0x84), puVar1 == (undefined4 *)0x0)) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x7c) = 1;
    if (puVar1[0x1e] == 0) {
      puVar2 = *(undefined4 **)(in_ECX + 0x74);
      uVar3 = puVar2[1];
      uVar4 = puVar2[2];
      *puVar1 = *puVar2;
      puVar1[1] = uVar3;
      puVar1[2] = uVar4;
      FUN_007cc3a0(&local_8,&local_10,&local_c);
      iVar5 = *(int *)(in_ECX + 0x84);
      *(undefined4 *)(iVar5 + 0xc) = local_10;
      *(undefined4 *)(iVar5 + 0x10) = local_c;
      *(undefined4 *)(iVar5 + 0x14) = local_8;
      *(undefined4 *)(*(int *)(in_ECX + 0x84) + 0x18) =
           *(undefined4 *)(*(int *)(in_ECX + 0x74) + 0x1c);
    }
    FUN_007d89b0(*(undefined4 *)(in_ECX + 0x84),param_1);
    iVar5 = *(int *)(in_ECX + 0x84);
    if ((param_2 < *(float *)(iVar5 + 0x74) * *(float *)(in_ECX + 0x70)) &&
       (*(float *)(iVar5 + 0x70) < *(float *)(iVar5 + 0x6c))) {
      FUN_007d8bf0();
      return;
    }
  }
  return;
}

