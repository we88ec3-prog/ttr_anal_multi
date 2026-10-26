
void FUN_006e87f0(void)

{
  float fVar1;
  double dVar2;
  double dVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  float10 fVar9;
  float10 fVar10;
  
  if (DAT_00fba7cc == 0) {
    iVar5 = FUN_00891268();
    if (iVar5 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar5 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar4 = *(char *)(iVar5 + 0x2fe);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar4 == '\0') {
    if (DAT_00fba7cc == 0) {
      iVar5 = FUN_00891268();
      if (iVar5 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar5 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    dVar2 = *(double *)(iVar5 + 0x2b8);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (DAT_00fba7cc == 0) {
      iVar5 = FUN_00891268();
      if (iVar5 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar5 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar5 = *(int *)(iVar5 + 0x2c0);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (DAT_00fba7cc == 0) {
      iVar6 = FUN_00891268();
      if (iVar6 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar6 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    dVar3 = *(double *)(iVar6 + 0x2a8);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar5 = iVar5 + 1;
    if (DAT_00fba7cc == 0) {
      iVar6 = FUN_00891268();
      if (iVar6 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar6 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar7 = DAT_00fba7cc;
    bVar8 = DAT_00d63d09 != '\0';
    *(int *)(iVar6 + 0x2c0) = iVar5;
    if (bVar8) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar7 = DAT_00fba7cc;
    }
    fVar9 = (float10)dVar3 - (float10)dVar2;
    if ((float10)1 < fVar9) {
      fVar10 = (float10)iVar5;
      if (iVar5 < 0) {
        fVar10 = fVar10 + (float10)4294967296.0;
      }
      fVar1 = (float)(fVar10 / fVar9);
      if (iVar7 == 0) {
        iVar5 = FUN_00891268();
        if (iVar5 == 0) {
          iVar7 = 0;
          DAT_00fba7cc = iVar7;
        }
        else {
          iVar7 = FUN_006df3d0();
          DAT_00fba7cc = iVar7;
        }
      }
      iVar5 = iVar7;
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        iVar5 = DAT_00fba7cc;
      }
      bVar8 = DAT_00d63d09 != '\0';
      *(float *)(iVar7 + 0x2c4) = fVar1;
      if (bVar8) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        iVar5 = DAT_00fba7cc;
      }
      if (iVar5 == 0) {
        iVar5 = FUN_00891268();
        if (iVar5 == 0) {
          iVar5 = 0;
          DAT_00fba7cc = iVar5;
        }
        else {
          iVar5 = FUN_006df3d0();
          DAT_00fba7cc = iVar5;
        }
      }
      iVar6 = iVar5;
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        iVar6 = DAT_00fba7cc;
      }
      bVar8 = DAT_00d63d09 != '\0';
      *(double *)(iVar5 + 0x2b8) = dVar3;
      if (bVar8) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        iVar6 = DAT_00fba7cc;
      }
      if (iVar6 == 0) {
        iVar5 = FUN_00891268();
        if (iVar5 == 0) {
          iVar6 = 0;
          DAT_00fba7cc = iVar6;
        }
        else {
          iVar6 = FUN_006df3d0();
          DAT_00fba7cc = iVar6;
        }
      }
      iVar5 = iVar6;
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        iVar5 = DAT_00fba7cc;
      }
      bVar8 = DAT_00d63d09 != '\0';
      *(undefined4 *)(iVar6 + 0x2c0) = 0;
      if (bVar8) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        iVar5 = DAT_00fba7cc;
      }
      if (iVar5 == 0) {
        iVar5 = FUN_00891268();
        if (iVar5 == 0) {
          iVar5 = 0;
          DAT_00fba7cc = iVar5;
        }
        else {
          iVar5 = FUN_006df3d0();
          DAT_00fba7cc = iVar5;
        }
      }
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      if (DAT_00d63d09 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      FUN_006ead50(iVar5 + 0x6cc,L"%0.2f fps ",(double)fVar1);
      return;
    }
  }
  return;
}

