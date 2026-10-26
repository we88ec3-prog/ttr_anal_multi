
void FUN_007bb150(int param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
                 )

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918aeb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_00891268(0x38,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = *in_ECX;
    puVar2[1] = in_ECX[1];
    uVar4 = in_ECX[2];
    puVar2[3] = param_3;
    puVar2[2] = uVar4;
    puVar2[4] = param_4;
    puVar2[9] = 0;
    puVar2[10] = 0xf;
    *(undefined1 *)(puVar2 + 5) = 0;
    pcVar3 = param_2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(param_2,(int)pcVar3 - (int)(param_2 + 1));
    puVar2[0xc] = param_5;
  }
  local_8 = 0xffffffff;
  if (0 < *(int *)(param_1 + 0x3c)) {
    uVar4 = FUN_007bad20(DAT_00fba838,puVar2,puVar2[3],puVar2[0xc]);
    puVar2[0xd] = uVar4;
  }
  FUN_007bb350();
  ExceptionList = local_10;
  return;
}

