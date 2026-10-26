
undefined4 FUN_006d6d80(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  
  iVar1 = param_1;
  FUN_004dd400(param_1,&param_1,&param_2);
  if (param_1 == *(int *)(iVar1 + 4)) {
    do {
      puVar2 = (undefined2 *)FUN_00891268(0x1c);
      if (puVar2 != (undefined2 *)0x0) {
        *puVar2 = 0;
        *(undefined4 *)(puVar2 + 2) = 0;
        *(undefined4 *)(puVar2 + 4) = 0;
        *(undefined4 *)(puVar2 + 6) = 0;
        *(undefined4 *)(puVar2 + 8) = 0;
        *(undefined4 *)(puVar2 + 0xc) = 0;
      }
      uVar3 = FUN_006d74f0();
      FUN_007c0b70(iVar1,uVar3);
      FUN_004dd400(iVar1,&param_1,&param_2);
    } while (param_1 == *(int *)(iVar1 + 4));
  }
  return *(undefined4 *)(param_1 + 0x18);
}

