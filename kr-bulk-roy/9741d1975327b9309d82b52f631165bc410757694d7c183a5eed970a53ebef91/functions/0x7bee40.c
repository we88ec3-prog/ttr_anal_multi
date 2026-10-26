
void FUN_007bee40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xc) == 0) {
    puVar1 = (undefined4 *)FUN_00891268(0x40);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1[8] = 0;
      puVar1[0xf] = 0;
      puVar1[9] = 0x3f800000;
      puVar1[10] = 0;
      puVar1[0xb] = 0;
      puVar1[0xc] = 0xbf800000;
      puVar1[0xd] = 0xbf800000;
      puVar1[0xe] = 0;
    }
    *(undefined4 **)(unaff_ESI + 0xc) = puVar1;
  }
  FUN_007e9ce0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
               param_11);
  return;
}

