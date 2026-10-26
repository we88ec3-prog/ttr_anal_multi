
int FUN_008f9270(undefined4 param_1)

{
  undefined *puVar1;
  int in_EAX;
  int iVar2;
  uint in_ECX;
  int in_EDX;
  int *piVar3;
  int *piVar4;
  int local_2c [6];
  undefined4 local_14;
  undefined *local_10;
  int *local_c;
  int local_8;
  
  iVar2 = *(int *)(in_EAX + 0x58);
  local_8 = in_EDX + 0x14;
  if (iVar2 != 0) {
    local_2c[1] = *(undefined4 *)(iVar2 + 0x10);
    local_2c[3] = 0;
    local_2c[2] = *(undefined4 *)(iVar2 + 0x14);
    local_2c[5] = (int)in_ECX >> 0x10 & 0xf;
    local_2c[4] = 0;
    local_14 = 0;
    iVar2 = FUN_008f9220();
    if ((iVar2 == 0) && (iVar2 = FUN_008f3fd0(&local_c), iVar2 == 0)) {
      puVar1 = (&PTR_DAT_00bebb70)[*(int *)(*local_c + 4)];
      *(int **)(local_8 + 0x84) = local_c;
      local_10 = puVar1;
      if (*(code **)(puVar1 + 0xc) == (code *)0x0) {
        piVar3 = local_2c;
        piVar4 = local_c;
        for (iVar2 = 7; piVar4 = piVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
          *piVar4 = *piVar3;
          piVar3 = piVar3 + 1;
        }
      }
      else {
        (**(code **)(puVar1 + 0xc))(local_c,local_2c);
      }
      if ((*(code **)(puVar1 + 0x14) == (code *)0x0) ||
         (iVar2 = (**(code **)(puVar1 + 0x14))(local_8 + 0xc,local_c), iVar2 == 0)) {
        iVar2 = FUN_008f7630(local_8,local_2c,param_1,in_ECX & 0xfffffffb | 0x801,0);
      }
    }
    return iVar2;
  }
  return 6;
}

