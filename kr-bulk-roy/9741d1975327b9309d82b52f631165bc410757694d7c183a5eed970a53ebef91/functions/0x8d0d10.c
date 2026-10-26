
undefined4
FUN_008d0d10(void *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int iVar1;
  
  _memset(param_1,0,0x5dc);
  iVar1 = FUN_008b8ff0(*(undefined4 *)(param_2 + 0x60),"postscript-cmaps");
  if (iVar1 == 0) {
    return 7;
  }
  *(int *)((int)param_1 + 0x544) = iVar1;
  FUN_008d0970(param_1,param_2,param_3,param_4,param_7);
  *(undefined4 *)((int)param_1 + 0x548) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)((int)param_1 + 0x54c) = param_5;
  *(undefined4 *)((int)param_1 + 0x5b8) = param_6;
  *(undefined4 *)((int)param_1 + 0x5bc) = param_8;
  *(undefined4 *)((int)param_1 + 0x5c0) = param_9;
  *(code **)((int)param_1 + 0x5c4) = FUN_008d0d10;
  *(code **)((int)param_1 + 0x5c8) = FUN_008d0dc0;
  *(code **)((int)param_1 + 0x5cc) = FUN_008d22e0;
  return 0;
}

