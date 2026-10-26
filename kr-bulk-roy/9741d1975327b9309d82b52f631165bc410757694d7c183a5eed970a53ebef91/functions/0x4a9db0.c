
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9db0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  undefined4 *puVar7;
  int in_ECX;
  undefined4 *puVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_10 = ExceptionList;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ceee;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar2 = *(undefined4 **)(in_ECX + 0x18);
  puVar3 = (undefined4 *)*puVar2;
  do {
    do {
      while( true ) {
        do {
          puVar8 = puVar3;
          if (puVar8 == puVar2) {
            piVar4 = *(int **)(*(int *)(in_ECX + 0x18) + 4);
            cVar1 = *(char *)((int)piVar4 + 0x11);
            while (cVar1 == '\0') {
              FUN_00852020(piVar4[2]);
              piVar5 = (int *)*piVar4;
              FUN_0089120c(piVar4);
              piVar4 = piVar5;
              cVar1 = *(char *)((int)piVar5 + 0x11);
            }
            *(int *)(*(int *)(in_ECX + 0x18) + 4) = *(int *)(in_ECX + 0x18);
            *(undefined4 *)*(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
            *(int *)(*(int *)(in_ECX + 0x18) + 8) = *(int *)(in_ECX + 0x18);
            *(undefined4 *)(in_ECX + 0x1c) = 0;
            if ((DAT_00fb7354 & 1) == 0) {
              DAT_00fb7354 = DAT_00fb7354 | 1;
              local_8 = 0;
              _eh_vector_constructor_iterator_(&DAT_00fb7358,0x10,4,FUN_00554050,FUN_00843020);
              DAT_00fb7398 = 0;
              DAT_00fb73ac = 0x400;
              DAT_00fb73b0 = 0x300;
              _DAT_00fb73b4 = 1;
              _atexit((_func_4879 *)&LAB_00bcd100);
              local_8 = 0xffffffff;
            }
            FUN_00553740(uVar6);
            ExceptionList = local_10;
            return;
          }
          *(undefined4 *)(puVar8[3] + 0x14) = 0;
          puVar3 = puVar8;
        } while (*(char *)((int)puVar8 + 0x11) != '\0');
        puVar3 = (undefined4 *)puVar8[2];
        if (*(char *)((int)puVar3 + 0x11) != '\0') break;
        cVar1 = *(char *)((int)*puVar3 + 0x11);
        puVar8 = (undefined4 *)*puVar3;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar8 + 0x11);
          puVar3 = puVar8;
          puVar8 = (undefined4 *)*puVar8;
        }
      }
      puVar3 = (undefined4 *)puVar8[1];
    } while (*(char *)((int)puVar3 + 0x11) != '\0');
    do {
      puVar7 = puVar3;
      puVar3 = puVar7;
      if (puVar8 != (undefined4 *)puVar7[2]) break;
      puVar3 = (undefined4 *)puVar7[1];
      puVar8 = puVar7;
    } while (*(char *)((int)puVar3 + 0x11) == '\0');
  } while( true );
}

