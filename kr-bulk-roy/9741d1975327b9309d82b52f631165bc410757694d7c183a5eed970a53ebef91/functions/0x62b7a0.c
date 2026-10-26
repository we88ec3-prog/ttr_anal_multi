
void FUN_0062b7a0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 *puVar5;
  int *in_ECX;
  int iVar6;
  undefined4 *puVar7;
  
  puVar2 = (undefined4 *)in_ECX[0x41];
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    iVar6 = 0;
    puVar7 = puVar3 + 5;
    do {
      pvVar4 = (void *)puVar7[-1];
      if (pvVar4 != (void *)*puVar7) {
        FID_conflict__memcpy(pvVar4,(void *)*puVar7,0);
        *puVar7 = pvVar4;
      }
      (**(code **)(*in_ECX + 0x1a0))(puVar7 + -1,puVar3[3],iVar6);
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 4;
    } while (iVar6 < 3);
    pvVar4 = (void *)puVar3[0x10];
    if (pvVar4 != (void *)puVar3[0x11]) {
      FID_conflict__memcpy(pvVar4,(void *)puVar3[0x11],0);
      puVar3[0x11] = pvVar4;
    }
    (**(code **)(*in_ECX + 0x1a0))(puVar3 + 0x10,puVar3[3],2);
    if (*(char *)((int)puVar3 + 0x89) == '\0') {
      puVar7 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar7 + 0x89) == '\0') {
        cVar1 = *(char *)((int)*puVar7 + 0x89);
        puVar3 = puVar7;
        puVar7 = (undefined4 *)*puVar7;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x89);
          puVar3 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x89);
        puVar5 = (undefined4 *)puVar3[1];
        puVar7 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar7 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x89);
          puVar5 = (undefined4 *)puVar3[1];
          puVar7 = puVar3;
        }
      }
    }
  }
  FUN_0062b1d0();
  return;
}

