
void FUN_004f6950(undefined4 param_1,short *param_2)

{
  short sVar1;
  short *psVar2;
  int in_EAX;
  short *psVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  
  psVar2 = param_2;
  FUN_008438c0(&param_1);
  if (param_2 == *(short **)(in_EAX + 0x104)) {
    puVar4 = (undefined2 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined2 *)0x0) {
      *(undefined4 *)(puVar4 + 8) = 0;
      *(undefined4 *)(puVar4 + 10) = 7;
      *puVar4 = 0;
    }
    psVar3 = psVar2;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar2,(int)psVar3 - (int)(psVar2 + 1) >> 1);
    uVar5 = FUN_0057ef20();
    FUN_0057e850(in_EAX + 0x100,uVar5);
  }
  else {
    psVar3 = psVar2;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    if ((int)psVar3 - (int)(psVar2 + 1) >> 1 != 0) {
      psVar3 = psVar2;
      do {
        sVar1 = *psVar3;
        psVar3 = psVar3 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar2,(int)psVar3 - (int)(psVar2 + 1) >> 1);
      return;
    }
  }
  return;
}

