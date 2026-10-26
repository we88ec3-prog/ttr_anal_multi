
undefined4 FUN_007f84e0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint in_EAX;
  int in_ECX;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_c;
  uint local_8;
  
  uVar2 = (*(int *)(in_ECX + 0x88) - *(int *)(in_ECX + 0x84)) / 0x48;
  uVar1 = in_EAX * 4;
  local_c = uVar1;
  if (uVar2 <= uVar1) {
    local_c = uVar2;
  }
  local_8 = uVar1 + 4;
  if (uVar2 <= uVar1 + 4) {
    local_8 = uVar2;
  }
  if (in_EAX == 0) {
    uVar5 = 2;
  }
  else {
    uVar5 = 1;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x100))(*(int **)(in_ECX + 4),uVar5);
  if (in_EAX < (uint)(*(int *)(in_ECX + 0x98) - *(int *)(in_ECX + 0x94) >> 2)) {
    (**(code **)(**(int **)(in_ECX + 4) + 0xd0))
              (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x80),
               *(undefined4 *)(uVar1 + *(int *)(in_ECX + 0x94)));
    (**(code **)(**(int **)(in_ECX + 4) + 0x98))
              (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x14),in_ECX + 0x18);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0xd0))
            (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0xa4),*(undefined4 *)(in_ECX + 0xa8));
  if (local_c < local_8) {
    iVar4 = local_c * 0x48;
    local_c = local_8 - local_c;
    puVar3 = (undefined4 *)(in_ECX + 0x70);
    do {
      (**(code **)(**(int **)(in_ECX + 4) + 0xd0))
                (*(int **)(in_ECX + 4),puVar3[-4],*(undefined4 *)(iVar4 + *(int *)(in_ECX + 0x84)));
      (**(code **)(**(int **)(in_ECX + 4) + 0x98))
                (*(int **)(in_ECX + 4),*puVar3,iVar4 + 8 + *(int *)(in_ECX + 0x84));
      puVar3 = puVar3 + 1;
      iVar4 = iVar4 + 0x48;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x104))(*(int **)(in_ECX + 4));
  (**(code **)(*param_1 + 0x148))(param_1,4,0,0,param_2,0,param_3);
  (**(code **)(**(int **)(in_ECX + 4) + 0x108))(*(int **)(in_ECX + 4));
  return 1;
}

