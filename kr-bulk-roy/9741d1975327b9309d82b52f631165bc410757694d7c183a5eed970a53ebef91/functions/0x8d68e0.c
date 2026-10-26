
void FUN_008d68e0(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 0x60) + 0x1c);
  FUN_008d6860();
  iVar1 = (**(code **)(iVar1 + 0x48))
                    (*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_2 + 0x2c),param_3,
                     param_4 | 8);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0xa0);
    puVar3 = (undefined4 *)(iVar1 + 0x18);
    puVar4 = (undefined4 *)(param_1 + 0x18);
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(iVar1 + 0x38);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(iVar1 + 0x3c);
    *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(iVar1 + 0x48);
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(iVar1 + 0x6c);
    *(undefined4 *)(param_1 + 0x70) = *(undefined4 *)(iVar1 + 0x70);
    *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(iVar1 + 0x74);
    *(undefined4 *)(param_1 + 0x78) = *(undefined4 *)(iVar1 + 0x78);
    *(undefined4 *)(param_1 + 0x7c) = *(undefined4 *)(iVar1 + 0x7c);
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(iVar1 + 0x4c);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(iVar1 + 0x50);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(iVar1 + 0x54);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(iVar1 + 0x58);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(iVar1 + 0x5c);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(iVar1 + 0x60);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(iVar1 + 100);
    *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(iVar1 + 0x68);
    *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(iVar1 + 0x80);
    *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(iVar1 + 0x84);
    *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(iVar1 + 0x88);
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(iVar1 + 0x8c);
  }
  return;
}

