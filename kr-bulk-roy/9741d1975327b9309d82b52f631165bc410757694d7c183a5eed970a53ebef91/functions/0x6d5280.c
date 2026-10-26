
void FUN_006d5280(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x74) != 0) && (*(int *)(in_ECX + 0x34) != 0)) &&
     (*(int *)(in_ECX + 4) != 0)) {
    iVar3 = FUN_00434740();
    iVar3 = *(int *)(iVar3 + 0x40);
    uVar2 = *(undefined4 *)(in_ECX + 0x74);
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x74))
              (*(int **)(in_ECX + 0x50),*(undefined4 *)(iVar3 + 0xb4),*(undefined4 *)(iVar3 + 0xb8),
               0x4b,0,0,1,in_ECX + 0x10,0);
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x5c))
              (*(int **)(in_ECX + 0x50),*(undefined4 *)(iVar3 + 0xb4),*(undefined4 *)(iVar3 + 0xb8),
               1,1,0x15,0,in_ECX + 0x14,0);
    (**(code **)(**(int **)(in_ECX + 0x14) + 0x48))(*(int **)(in_ECX + 0x14),0,in_ECX + 0x18);
    puVar1 = (undefined4 *)(in_ECX + 0x1c);
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x5c))
              (*(int **)(in_ECX + 0x50),uVar2,uVar2,1,1,0x15,0,puVar1,0);
    (**(code **)(*(int *)*puVar1 + 0x48))((int *)*puVar1,0,in_ECX + 0x20);
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x5c))
              (*(int **)(in_ECX + 0x50),uVar2,uVar2,1,1,0x15,0,in_ECX + 0x24,0);
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x48))(*(int **)(in_ECX + 0x24),0,in_ECX + 0x28);
    (**(code **)(**(int **)(in_ECX + 0x50) + 0x5c))
              (*(int **)(in_ECX + 0x50),uVar2,uVar2,1,1,0x15,0,in_ECX + 0x2c,0);
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0x48))(*(int **)(in_ECX + 0x2c),0,in_ECX + 0x30);
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x118))(*(int **)(in_ECX + 0x34));
    (**(code **)(**(int **)(in_ECX + 0x34) + 0xd0))
              (*(int **)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x3c),
               *(undefined4 *)(in_ECX + 0x14));
    (**(code **)(**(int **)(in_ECX + 0x34) + 0xd0))
              (*(int **)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x44),*puVar1);
    (**(code **)(**(int **)(in_ECX + 0x34) + 0xd0))
              (*(int **)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x48),
               *(undefined4 *)(in_ECX + 0x24));
    (**(code **)(**(int **)(in_ECX + 0x34) + 0xd0))
              (*(int **)(in_ECX + 0x34),*(undefined4 *)(in_ECX + 0x4c),
               *(undefined4 *)(in_ECX + 0x2c));
    (**(code **)(**(int **)(in_ECX + 0x34) + 0x104))(*(int **)(in_ECX + 0x34));
  }
  return;
}

