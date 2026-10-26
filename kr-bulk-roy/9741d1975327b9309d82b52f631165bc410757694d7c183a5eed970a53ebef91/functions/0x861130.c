
void FUN_00861130(int param_1)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  undefined4 ****ppppuVar3;
  int unaff_EBX;
  int unaff_ESI;
  int *piStack_70;
  undefined4 uStack_6c;
  char *pcStack_68;
  uint uStack_64;
  int iVar4;
  int iStack_54;
  int *piStack_50;
  int local_4c;
  undefined4 ***apppuStack_48 [4];
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_2c;
  void *pvStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00920458;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_54;
  uStack_64 = DAT_00d61f20 ^ (uint)&stack0xffffffa0;
  ExceptionList = &local_14;
  pcStack_68 = (char *)param_1;
  uStack_6c = 0x861176;
  FUN_00784fd0();
  local_4c = *(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x30) >> 2;
  piStack_70 = (int *)(in_ECX + 0x40);
  if (piStack_70 != (int *)0x0) {
    pcStack_68 = (char *)0x0;
    uStack_6c = 4;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88));
  }
  piStack_70 = (int *)(in_ECX + 0x48);
  if (piStack_70 != (int *)0x0) {
    pcStack_68 = (char *)0x0;
    uStack_6c = 4;
    FUN_00721910(*(undefined4 *)(param_1 + 0x88));
  }
  pcStack_68 = (char *)0x0;
  uStack_6c = 4;
  piStack_70 = &local_4c;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88));
  iVar4 = 0;
  if (0 < unaff_ESI) {
    do {
      local_4c = **(int **)(*(int *)(in_ECX + 0x30) + iVar4 * 4);
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&local_4c,4,0);
      (**(code **)(**(int **)(param_1 + 0x90) + 0x58))
                (*(int *)(*(int *)(in_ECX + 0x30) + (int)piStack_70 * 4) + 4,&stack0xffffffa0);
      local_4c = 0xf;
      piStack_50 = (int *)0x0;
      pcVar2 = pcStack_68;
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcStack_68,(int)pcVar2 - (int)(pcStack_68 + 1));
      uStack_34 = 0;
      piStack_70 = piStack_50;
      FUN_00721910(*(undefined4 *)(param_1 + 0x88),&piStack_70,4,0);
      if (uStack_34 < 0x10) {
        ppppuVar3 = apppuStack_48;
LAB_0086128e:
        if (unaff_EBX != 0) {
          FUN_00721910(*(undefined4 *)(param_1 + 0x88),ppppuVar3,unaff_EBX,0);
        }
      }
      else {
        ppppuVar3 = (undefined4 ****)apppuStack_48[0];
        if ((undefined4 ****)apppuStack_48[0] != (undefined4 ****)0x0) goto LAB_0086128e;
      }
      local_1c = 0xffffffff;
      if (0xf < uStack_34) {
        FUN_0089120c(apppuStack_48[0]);
      }
      iVar4 = 1;
      uStack_34 = 0xf;
      uStack_38 = 0;
      apppuStack_48[0] = (undefined4 ***)((uint)apppuStack_48[0] & 0xffffff00);
      in_ECX = iStack_54;
    } while (1 < unaff_ESI);
  }
  ExceptionList = pvStack_24;
  pcStack_68 = (char *)0x861302;
  __security_check_cookie(uStack_2c ^ (uint)&uStack_64);
  return;
}

