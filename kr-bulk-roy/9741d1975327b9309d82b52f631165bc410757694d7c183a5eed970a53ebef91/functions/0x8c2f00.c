
void FUN_008c2f00(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x104);
  iVar2 = (**(code **)(param_1 + 0x1fc))(param_1,0x6d617870,param_2,0);
  if (iVar2 == 0) {
    iVar2 = FUN_008bacd0(param_2,&DAT_00bd7e24,piVar1);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x10a) = 0;
      *(undefined4 *)(param_1 + 0x10e) = 0;
      *(undefined4 *)(param_1 + 0x112) = 0;
      *(undefined4 *)(param_1 + 0x116) = 0;
      *(undefined4 *)(param_1 + 0x11a) = 0;
      *(undefined4 *)(param_1 + 0x11e) = 0;
      *(undefined2 *)(param_1 + 0x122) = 0;
      if (0xffff < *piVar1) {
        iVar2 = FUN_008bacd0(param_2,&DAT_00bd7e34,piVar1);
        if (iVar2 == 0) {
          if (*(ushort *)(param_1 + 0x118) < 0x40) {
            *(undefined2 *)(param_1 + 0x118) = 0x40;
          }
          if (0xfffb < *(ushort *)(param_1 + 0x114)) {
            *(undefined2 *)(param_1 + 0x114) = 0xfffb;
          }
          if (100 < *(ushort *)(param_1 + 0x122)) {
            *(undefined2 *)(param_1 + 0x122) = 100;
          }
        }
      }
    }
  }
  return;
}

