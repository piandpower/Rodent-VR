﻿using System;
using System.Windows.Interop;
using MahApps.Metro.Controls;
using RodentVRSettings.Models.Configuration;

namespace RodentVRSettings
{
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>
	public partial class MainWindow : MetroWindow//, Contracts.RodentVRSettingsViewContract
	{
		//public Contracts.RodentVRSettingsPresenterContract Presenter { get; set; }
		private ConfigurationSettings settings;

		public MainWindow()
		{
			InitializeComponent();

			this.settings = new ConfigurationSettings();
			viewAirPuffers.Init(this.settings);

			viewBehaviorRecording.Init(this.settings);
			viewMaterials.Init(this.settings);
			viewInitialMaze.Init(this.settings);

			//this.Presenter = new Presenters.BehaviorVisualizerPresenter();
			//this.Presenter.View = this;
			//this.Presenter.Reset();
		}

		protected override void OnSourceInitialized(EventArgs e)
		{
			base.OnSourceInitialized(e);
			viewMouseInput.Init(this.settings, this.CriticalHandle);
			HwndSource source = HwndSource.FromHwnd(this.CriticalHandle);
			source.AddHook(new HwndSourceHook(viewMouseInput.RawMouseInputDevice.WndProc));
		}
	}
}
