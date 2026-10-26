
void FUN_008c3200(int param_1,undefined4 param_2)

{
  int iVar1;
  ushort *puVar2;
  
  iVar1 = (**(code **)(param_1 + 0x1fc))(param_1,0x4f532f32,param_2,0);
  if (iVar1 == 0) {
    puVar2 = (ushort *)(param_1 + 0x16c);
    iVar1 = FUN_008bacd0(param_2,&DAT_00bd7ea0,puVar2);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x1c4) = 0;
      *(undefined4 *)(param_1 + 0x1c8) = 0;
      *(undefined4 *)(param_1 + 0x1cc) = 0;
      *(undefined4 *)(param_1 + 0x1bc) = 0;
      *(undefined4 *)(param_1 + 0x1c0) = 0;
      *(undefined2 *)(param_1 + 0x1d0) = 0xffff;
      if (*puVar2 != 0) {
        iVar1 = FUN_008bacd0(param_2,&DAT_00bd7f50,puVar2);
        if ((iVar1 == 0) && (1 < *puVar2)) {
          iVar1 = FUN_008bacd0(param_2,&DAT_00bd7f60,puVar2);
          if ((iVar1 == 0) && (4 < *puVar2)) {
            FUN_008bacd0(param_2,&DAT_00bd7f7c,puVar2);
          }
        }
      }
    }
  }
  return;
}

