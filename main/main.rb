game_state = Game::GameState
States = Game::Constants::States

Game::SaveState.load do |save_state|
  game_state.transition_to(States::EGG, 10)
end

Game::Events.state_change(States::ANY, States::EGG) do
  game_state.transition_to(States::HATCHING, 5000)
end

Game::Events.state_change(States::EGG, States::HATCHING) do
  game_state.transition_to(States::HATCHED, 3000)
end

Game::Events.state_change(States::HATCHING, States::HATCHED) do
  game_state.transition_to(States::EGG, 3000)
end